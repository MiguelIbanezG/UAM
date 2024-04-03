<template>
  <div id="formulario-usuario">
    <form @submit.prevent="enviarFormulario">
      <div class="container">
        <div class="row">
          <div class="col-md-4">
            <div class="form-group">
              <label>Nombre</label>
              <input
                ref="nombre"
                v-model="usuario.nombreUsuario"
                type="text"
                class="form-control"
                :class="{ 'is-invalid': procesando && nombreInvalido }"
                @focus="resetEstado"
                @keypress="resetEstado"
              />
            </div>
          </div>
        </div>
        <div class="row">
          <div class="col-md-4">
            <div class="form-group">
              <button class="btn-sm btn-primary">Agnadir usuario</button>
            </div>
          </div>
        </div>
      </div>
      <div class="container">
        <div class="row">
          <div class="col-md-12">
            <div
              v-if="error && procesando"
              class="alert alert-danger"
              role="alert"
            >
              Debes rellenar todos los campos!
            </div>
            <div v-if="correcto" class="alert alert-success" role="alert">
              La usuario ha sido agregada correctamente!
            </div>
          </div>
        </div>
      </div>
    </form>
  </div>
</template>

<script>
export default {
  name: "formulario-usuario",
  data() {
    return {
      procesando: false,
      correcto: false,
      error: false,
      usuario: {
        nombreUsuario: "",
      },
    };
  },
  methods: {
    enviarFormulario() {
      this.procesando = true;
      this.resetEstado();
      // Comprobamos la presencia de errores
      if (this.nombreInvalido) {
        this.error = true;
        return;
      }
      this.$emit("add-usuario", this.usuario);
      this.$refs.nombreUsuario.focus();

      this.error = false;
      this.correcto = true;
      this.procesando = false;
      // Restablecemos el valor de la variables
      this.usuario = {
        nombreUsuario: "",
      };
    },
    resetEstado() {
      this.correcto = false;
      this.error = false;
    },
  },
  computed: {
        nombreInvalido() {
          return this.usuario.nombreUsuario.length < 1;
        },
      },
};
</script>

<style scoped>
form {
  margin-bottom: 2rem;
}
</style>