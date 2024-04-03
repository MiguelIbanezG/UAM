<!-- src/components/Tablasuscripciones.vue -->
<template>
  <div id="tabla-suscripciones">
    <div v-if="!suscripciones.length" class="alert alert-info" role="alert">
      No se han agregado suscripciones
    </div>
    <table class="table">
      <thead>
        <tr>
          <th>Suscriptor</th>
          <th>Canal</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="suscripcion in suscripciones" :key="suscripcion.id">
          <td v-if="editando === suscripcion.id">
            <input type="text" class="form-control" v-model="suscripcion.canal" />
          </td>
          <td v-else>
            {{ suscripcion.canal }}
          </td>
          <td>
            <button class="btn-sm btn-info" @click="editarSuscripcion(suscripcion)">
              &#x1F58A; Editar
            </button>
          </td>

          <td v-if="editando === suscripcion.id">
            <button class="btn-sm btn-success" @click="guardarSuscripcion(suscripcion)">
              &#x1F5AB; Guardar
            </button>
            
            <button
              class="btn-sm btn-secondary ml-2"
              @click="cancelarEdicion(suscripcion)"
            >
              &#x1F5D9; Cancelar
            </button>
          </td>
          <td v-else>
            <button
              class="btn-sm btn-danger ml-2"
              @click="$emit('delete-suscripcion', suscripcion.id)"
            >
              &#x1F5D1; Eliminar
            </button>
          </td>
        </tr>
      </tbody>
    </table>
  </div>
</template>
<script>
export default {
  name: "tabla-suscripciones",
  props: {
    suscripciones: Array,
  },
  methods: {
  },
  data() {
    return {
      editando: null,
    };
  },
};
</script>
<style scoped></style>