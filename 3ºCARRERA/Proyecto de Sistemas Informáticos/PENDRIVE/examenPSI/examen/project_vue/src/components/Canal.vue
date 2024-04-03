<template>
    <div>
      <h2>Lista de Canales</h2>
      <table>
        <thead>
          <tr>
            <th>ID</th>
            <th>Nombre</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="canal in canales" :key="canal.id">
            <td>{{ canal.id }}</td>
            <td>{{ canal.nombreCanal }}</td>
          </tr>
        </tbody>
      </table>
    </div>
  </template>
  
  <script>
  import axios from 'axios';
  
  export default {
    name: 'Canal',
    data() {
      return {
        canales: [],
      };
    },
    mounted() {
      axios
        .get('http://localhost:8000/api/v1/canal')
        .then(response => {
          this.canales = response.data;
        })
        .catch(error => {
          console.log(error);
        });
    },
  };
  </script>