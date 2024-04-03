<!-- src/components/Tablausuarios.vue -->
<template>
  <div id="tabla-usuarios">
    <div v-if="!usuarios.length" class="alert alert-info" role="alert">
      No se han agregado usuarios
    </div>
    <table class="table">
      <thead>
        <tr>
          <th>Nombre</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="usuario in usuarios" :key="usuario.id">
          <td v-if="editando === usuario.id">
            <input type="text" class="form-control" v-model="usuario.nombreUsuario" />
          </td>
          <td v-else>
            {{ usuario.nombreUsuario }}
          </td>
          <td>
            <button class="btn-sm btn-info" @click="editarusuario(usuario)">
              &#x1F58A; Editar
            </button>
          </td>

          <td v-if="editando === usuario.id">
            <button class="btn-sm btn-success" @click="guardarusuario(usuario)">
              &#x1F5AB; Guardar
            </button>
            
            <button
              class="btn-sm btn-secondary ml-2"
              @click="cancelarEdicion(usuario)"
            >
              &#x1F5D9; Cancelar
            </button>
          </td>
          <td v-else>
            <button
              class="btn-sm btn-danger ml-2"
              @click="$emit('delete-usuario', usuario.id)"
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
  name: "tabla-usuarios",
  props: {
    usuarios: Array,
  },
  methods: {
    editarusuario(usuario) {
      this.usuarioEditada = Object.assign({}, usuario);
      this.editando = usuario.id;
    },
    guardarusuario(usuario) {
      if (
        !usuario.nombreUsuario.length
      ) {
        return;
      }
      this.$emit("actualizar-usuario", usuario.id, usuario);
      this.editando = null;
    },
    cancelarEdicion(usuario) {
      Object.assign(usuario, this.usuarioEditada);
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