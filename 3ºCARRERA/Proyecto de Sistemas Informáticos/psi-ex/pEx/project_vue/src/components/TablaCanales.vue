<!-- src/components/Tablacanales.vue -->
<template>
  <div id="tabla-canales">
    <div v-if="!canales.length" class="alert alert-info" role="alert">
      No se han agregado canales
    </div>
    <table class="table">
      <thead>
        <tr>
          <th>Nombre</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="canal in canales" :key="canal.id">
          <td v-if="editando === canal.id">
            <input type="text" class="form-control" v-model="canal.nombreCanal" />
          </td>
          <td v-else>
            {{ canal.nombreCanal }}
          </td>
          <td>
            <button class="btn-sm btn-info" @click="editarCanal(canal)">
              &#x1F58A; Editar
            </button>
          </td>

          <td v-if="editando === canal.id">
            <button class="btn-sm btn-success" @click="guardarCanal(canal)">
              &#x1F5AB; Guardar
            </button>
            
            <button
              class="btn-sm btn-secondary ml-2"
              @click="cancelarEdicion(canal)"
            >
              &#x1F5D9; Cancelar
            </button>
          </td>
          <td v-else>
            <button
              class="btn-sm btn-danger ml-2"
              @click="$emit('delete-canal', canal.id)"
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
  name: "tabla-canales",
  props: {
    canales: Array,
  },
  methods: {
    editarCanal(canal) {
      this.canalEditada = Object.assign({}, canal);
      this.editando = canal.id;
    },
    guardarCanal(canal) {
      if (
        !canal.nombreCanal.length
      ) {
        return;
      }
      this.$emit("actualizar-canal", canal.id, canal);
      this.editando = null;
    },
    cancelarEdicion(canal) {
      Object.assign(canal, this.canalEditada);
      this.editando = null;
    },
  },
  data() {
    return {
      editando: null,
    };
  },
};
</script>
<style scoped></style>