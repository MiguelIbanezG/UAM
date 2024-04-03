from typing import Any, Dict
from django.shortcuts import render
from .models import canal, suscripcion, usuario
from django.views.generic import ListView

from rest_framework import viewsets
from rest_framework.response import Response
from rest_framework import status

from . import serializers
# Create your views here.


class SubscripcionesListView(ListView):
    model=suscripcion
    template_name = "application/canal.html"
    
    def get_context_data(self, **kwargs: Any) :
    
        context_data = super().get_context_data(**kwargs)
        context_data['suscripciones'] = suscripcion.objects.filter(id=self.kwargs['pk'])
        return context_data
    

#guess view set
class UsuarioViewSet(viewsets.ModelViewSet):
    queryset = usuario.objects.all()
    serializer_class = serializers.UsuarioSerializer
    
    def retrieve(self, request, *args, **kwargs):
        data = {
            "id" : int (kwargs.get('pk'))
        }

        u = usuario.objects.filter(id=data['id'])
        if u.exists():
            
            serializer = self.serializer_class(u.first())

            return Response(data=serializer.data, status=status.HTTP_200_OK)
        
        return Response(status=status.HTTP_400_BAD_REQUEST)

    def create(self, request, *args, **kwargs):
        data = request.data

        if not usuario.objects.filter(nombreUsuario=data['nombreUsuario']).exists():
            
            u = usuario.objects.create(nombreUsuario=data['nombreUsuario'])
            serializer = self.serializer_class(u)
            return Response(data=serializer.data, status=status.HTTP_201_CREATED)
        
        return Response( status=status.HTTP_400_BAD_REQUEST)

    def update(self, request, *args, **kwargs):
        data = request.data
        u = usuario.objects.filter(id=data['id'])
        if u.exists():
            u.update(nombreUsuario=data['nombreUsuario'])
            u = usuario.objects.filter(id=data['id'])

            serializer = self.serializer_class(u, many=True)
            return Response(data=serializer.data, status=status.HTTP_200_OK)

        return Response(status=status.HTTP_400_BAD_REQUEST)

    def destroy(self, request, *args, **kwargs):
        data = {
            "id" : int (kwargs.get('pk'))
        }

        u = usuario.objects.filter(id=data['id'])
        if u.exists():
            u.delete()
            return Response(status=status.HTTP_202_ACCEPTED)

        return Response(status=status.HTTP_400_BAD_REQUEST)

class CanalViewSet(viewsets.ModelViewSet):
    queryset = canal.objects.all()
    serializer_class = serializers.CanalSerializer
    
    def retrieve(self, request, *args, **kwargs):
        data = {
            "id" :  (kwargs.get('pk'))
        }


        c = canal.objects.filter(id=data['id'])
        if c.exists():
            serializer = self.serializer_class(c.first())
            
        return Response(data=serializer.data, status=status.HTTP_200_OK)

    def create(self, request, *args, **kwargs):
        data = request.data
        if not canal.objects.filter(nombreCanal=data['nombreCanal']).exists():
            
            c = canal.objects.create(nombreCanal=data['nombreCanal'])
            serializer = self.serializer_class(c)
            
            return Response(data=serializer.data, status=status.HTTP_201_CREATED)
        
        return Response(status=status.HTTP_400_BAD_REQUEST)

    
    def update(self, request, *args, **kwargs):
        data = request.data

        c = canal.objects.filter(id=data['id'])
        if c.exists():
            c.update(nombreCanal=data['nombreCanal'])
            serializer = self.serializer_class(c, many=True)

            return Response(data=serializer.data, status=status.HTTP_200_OK)

        return Response(status=status.HTTP_400_BAD_REQUEST)


    def destroy(self, request, *args, **kwargs):
        data = {
            "id" : int (kwargs.get('pk'))
        }

        c = canal.objects.filter(id=data['id'])
        if c.exists():
            c.delete()
            return Response(status=status.HTTP_202_ACCEPTED)

        return Response(status=status.HTTP_400_BAD_REQUEST)



class SuscripcionViewSet(viewsets.ModelViewSet):
    queryset = suscripcion.objects.all()
    serializer_class = serializers.SuscripcionSerializer
    
    def retrieve(self, request, *args, **kwargs):
        data = {
            "id" : int (kwargs.get('pk'))
        }

        u = suscripcion.objects.filter(id=data['id'])
        if u.exists():
            
            serializer = self.serializer_class(u.first())
            
        return Response(data=serializer.data, status=status.HTTP_200_OK)

    def create(self, request, *args, **kwargs):
        data = request.data

        c = canal.objects.filter(id=data['canal'])
        if c.exists():

            u = usuario.objects.filter(id=data['usuario'])

            if u.exists():
                if not suscripcion.objects.filter(usuario=u.first(),
                                                  canal=c.first()).exists():

                    s = suscripcion.objects.create(usuario=u.first(),
                                               canal=c.first(),
                                               fechaDeSuscripcion=data['fechaDeSuscripcion'])
                
                    serializer = self.serializer_class(s)

                    return Response(data=serializer.data, status=status.HTTP_201_CREATED)
        
        return Response(status=status.HTTP_400_BAD_REQUEST)

    def update(self, request, *args, **kwargs):
        data = request.data

        s = suscripcion.objects.filter(id=data['id'])
        if s.exists():
            c = canal.objects.filter(id=data['canal'])
            if c.exists():
                u = usuario.objects.filter(id=data['usuario'])
                if u.exists():
                    s.update(canal=c,
                             usuario=u,
                             fechaDeSuscripcion=data['fechaDeSuscripcion'])
                    
                    serializer = self.serializer_class(s)

                    return Response(data=serializer.data,status=status.HTTP_204_NO_CONTENT)

        return Response(status=status.HTTP_400_BAD_REQUEST)

    def destroy(self, request, *args, **kwargs):
        data = {
            "id" : int (kwargs.get('pk'))
        }


        s = suscripcion.objects.filter(id=data['id'])
        if s.exists():
            s.delete()
            return Response(status=status.HTTP_202_ACCEPTED)

        return Response(status=status.HTTP_400_BAD_REQUEST)

