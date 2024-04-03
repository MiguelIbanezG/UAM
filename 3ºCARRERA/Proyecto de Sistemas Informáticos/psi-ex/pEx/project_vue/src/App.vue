<template>
  <div id="app" class="container">
    <div class="row">
      <div class="col-md-12">
        <h1>Usuario</h1>
        <formulario-usuario @add-usuario="agregarUsuario" />
      </div>
    </div>
    <div class="row">
      <div class="col-md-12">
        <tabla-usuarios
          :usuarios="usuarios"
          @delete-usuario="eliminarUsuario"
          @actualizar-usuario="actualizarUsuario"
        />
      </div>
    </div>
    <div class="row">
      <div class="col-md-12">
        <h1>Canal</h1>
        <formulario-canal @add-canal="agregarCanal" />
      </div>
    </div>
    <div class="row">
      <div class="col-md-12">
        <tabla-canales
          :canales="canales"
          @delete-canal="eliminarCanal"
          @actualizar-canal="actualizarCanal"
        />
      </div>
    </div>
  </div>
</template>

<script>
import TablaUsuarios from "@/components/TablaUsuarios.vue";
import FormularioUsuario from "@/components/FormularioUsuario.vue";
import TablaCanales from "@/components/TablaCanales.vue";
import FormularioCanal from "@/components/FormularioCanal.vue";
import TablaSuscripciones from "@/components/TablaSuscripciones.vue";

export default {
  name: "app",
  components: {
    FormularioUsuario,
    TablaUsuarios,
    TablaCanales,
    FormularioCanal,
    TablaSuscripciones
  },

  data() {
    return {
      usuarios: [],
      canales: [],
    };
  },
  methods: {
    async listadoUsuarios() {
      try {
        const response = await fetch(
          import.meta.env.VITE_API_USUARIO
        );
        this.usuarios = await response.json();

      } catch (error) {
        console.error(error);
      }
    },
    async agregarUsuario(usuario) {
      try {
        const response = await fetch(
          import.meta.env.VITE_API_USUARIO,
          {
            method: "POST",
            headers: { "Content-type": "application/json; charset=UTF-8" },
            body: JSON.stringify(usuario),
          }
        );
        const usuarioCreada = await response.json();

        this.usuarios = [...this.usuarios, usuarioCreada];

      } catch (error) {
        console.error(error);
      }
    },
    async eliminarUsuario(usuario_id) {
      try {
        await fetch(
          import.meta.env.VITE_API_USUARIO +
            usuario_id +
            "/",
          {
            method: "DELETE",
          }
        );
        this.usuarios = this.usuarios.filter((u) => u.id !== usuario_id);
      } catch (error) {
        console.error(error);
      }
    },
    async actualizarUsuario(id, usuarioActualizada) {
      try {
        const response = await fetch(
          import.meta.env.VITE_API_USUARIO +
            usuarioActualizada.id +
            "/",
          {
            method: "PUT",
            body: JSON.stringify(usuarioActualizada),
            headers: { "Content-type": "application/json; charset=UTF-8" },
          }
        );
        const usuarioArray= await response.json();
        const usuarioActualizadaJS = usuarioArray[0]

        this.usuarios = this.usuarios.map((u) =>
          u.id === usuarioActualizada.id ? usuarioActualizadaJS : u
        );
      } catch (error) {
        console.error(error);
      }
    },


    async listadoCanales() {
      try {
        const response = await fetch(
          import.meta.env.VITE_API_CANAL
        );
        this.canales = await response.json();

      } catch (error) {
        console.error(error);
      }
    },
    async agregarCanal(canal) {
      try {

        const response = await fetch(
          import.meta.env.VITE_API_CANAL,
          {
            method: "POST",
            headers: { "Content-type": "application/json; charset=UTF-8" },
            body: JSON.stringify(canal),
          }
        );
        const canalCreada = await response.json();
        this.canales = [...this.canales, canalCreada];

      } catch (error) {
        console.error(error);
      }
    },
    async eliminarCanal(canal_id) {
      try {
        await fetch(
          import.meta.env.VITE_API_CANAL +
          canal_id +
            "/",
          {
            method: "DELETE",
          }
        );
        this.canales = this.canales.filter((c) => c.id !== canal_id);
      } catch (error) {
        console.error(error);
      }
    },
    async actualizarCanal(id, canalActualizada) {
      try {
        const response = await fetch(
          import.meta.env.VITE_API_CANAL +
            canalActualizada.id +
            "/",
          {
            method: "PUT",
            body: JSON.stringify(canalActualizada),
            headers: { "Content-type": "application/json; charset=UTF-8" },
          }
        );
        const canalArray = await response.json();
        const canalActualizadaJS = canalArray[0]

        this.canales = this.canales.map((u) =>
          u.id === canalActualizada.id ? canalActualizadaJS : u
        );
      } catch (error) {
        console.error(error);
      }
    },
  },
  mounted() {
    this.listadoUsuarios();
    this.listadoCanales();
  },
};
</script>

<style>
button {
  background: #009435;
  border: 1px solid #009435;
}

#app {
  width: 100vw;
  height: 100vh;
}
</style>