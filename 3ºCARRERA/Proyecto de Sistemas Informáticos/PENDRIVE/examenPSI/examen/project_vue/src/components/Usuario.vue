<template>
    <div>
      <h2>Lista de Usuarios</h2>
      <table>
        <thead>
          <tr>
            <th>ID</th>
            <th>Nombre</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="usuario in usuarios" :key="usuario.id">
            <td>{{ usuario.id }}</td>
            <td>{{ usuario.nombreUsuario }}</td>
          </tr>
        </tbody>
      </table>
    </div>
  </template>
  
  <script>
  import axios from 'axios';
  
  export default {
    name: 'Usuario',
    data() {
      return {
        usuarios: [],
      };
    },
    mounted() {
      axios
        .get('http://localhost:8000/api/v1/usuario')
        .then(response => {
          this.usuarios = response.data;
        })
        .catch(error => {
          console.log(error);
        });
    },
  };
  </script>