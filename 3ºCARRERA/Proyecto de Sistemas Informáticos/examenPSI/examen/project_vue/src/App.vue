

<template>
  <main>
    <v-app id="app" class="container">
      <div class="position-absolute top-50 start-50 translate-middle">
        <div class="col-md-12">
            <router-view></router-view>
        </div>
      </div>
   </v-app>
  </main>


</template>

<script>

import Canal from '@/components/Canal.vue'
import Usuario from '@/components/Usuario.vue'
import Suscripcion from '@/components/Suscripcion.vue'


export default {
  name: 'app',
  components: {
    Canal,
    Usuario,
    Suscripcion
  },
  
  data() {
    return {
      users: [],
      channels: [],
      subscriptions: [],
    };

  },
  mounted: function () {
    axios
      .get('http://localhost:3000/usuarios')
      .then(response => (this.users = response.data))
      .catch(error => console.log(error));
    axios
      .get('http://localhost:3000/canales')
      .then(response => (this.channels = response.data))
      .catch(error => console.log(error));
    axios
      .get('http://localhost:3000/suscripciones')
      .then(response => (this.subscriptions = response.data))
      .catch(error => console.log(error));
  },
  methods: {
   
    timerFun() {
      let self = this;

      this.timer = setInterval(function () {
        self.get_game();
      }, 1000);
    },
  }
}
</script>

<style scoped>
header {
  line-height: 1.5;
}

.logo {
  display: block;
  margin: 0 auto 2rem;
}

@media (min-width: 1024px) {
  header {
    display: flex;
    place-items: center;
    padding-right: calc(var(--section-gap) / 2);
  }

  .logo {
    margin: 0 2rem 0 0;
  }

  header .wrapper {
    display: flex;
    place-items: flex-start;
    flex-wrap: wrap;
  }
}
</style>
