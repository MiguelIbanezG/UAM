<template>
    <div>
      <h2>Lista de Suscripciones</h2>
      <table>
        <thead>
          <tr>
            <th>ID</th>
            <th>Canal</th>
            <th>Usuario</th>
            <th>Fecha de Suscripción</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="suscripcion in suscripciones" :key="suscripcion.id">
            <td>{{ suscripcion.id }}</td>
            <td>{{ suscripcion.canal.nombreCanal }}</td>
            <td>{{ suscripcion.usuario.nombreUsuario }}</td>
            <td>{{ suscripcion.fechaDeSuscripcion }}</td>
          </tr>
        </tbody>
      </table>
    </div>
  </template>
  
  <script>
  import axios from 'axios';
  
  export default {
    name: 'Suscripcion',
    data() {
      return {
        suscripciones: [],
      };
    },
    mounted() {
      axios
        .get('http://localhost:8000/api/v1/suscripcion')
        .then(response => {
          this.suscripciones = response.data;
        })
        .catch(error => {
          console.log(error);
        });
    },
  };
  </script>