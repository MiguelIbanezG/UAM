<template>
  <div id="formulario-canal">
    <form @submit.prevent="enviarFormulario">
      <div class="container">
        <div class="row">
          <div class="col-md-4">
            <div class="form-group">
              <label>Nombre</label>
              <input
                ref="nombre"
                v-model="canal.nombreCanal"
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
              <button class="btn-sm btn-primary">Agnadir canal</button>
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
              La canal ha sido agregada correctamente!
            </div>
          </div>
        </div>
      </div>
    </form>
  </div>
</template>

<script>
export default {
  name: "formulario-canal",
  data() {
    return {
      procesando: false,
      correcto: false,
      error: false,
      canal: {
        nombreCanal: "",
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
      this.$emit("add-canal", this.canal);
      this.$refs.nombreCanal.focus();

      this.error = false;
      this.correcto = true;
      this.procesando = false;
      // Restablecemos el valor de la variables
      this.canal = {
        nombreCanal: "",
      };
    },
    resetEstado() {
      this.correcto = false;
      this.error = false;
    },
  },
  computed: {
        nombreInvalido() {
          return this.canal.nombreCanal.length < 1;
        },
      },
};
</script>

<style scoped>
form {
  margin-bottom: 2rem;
}
</style>