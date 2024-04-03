<script setup>
import { RouterLink, RouterView } from "vue-router";
</script>
<template>
  <main>

    <v-app id="app" class="container d-flex justify-content-center " >
      <div class="col-md-4 ">
          <router-view></router-view>
      </div>
    </v-app>

  </main>
</template>

<script>

import GameJoin from '@/components/GameJoin.vue'
import GameStart from '@/components/GameStart.vue'
import GameAnswer from '@/components/GameAnswer.vue'



export default {
  name: 'app',
  components: {
    GameJoin,
    GameStart,
    GameAnswer
  },
  props:{
  },

  data() {
    return {
      BackgroundColor: 'coral',

    }

  },
  mounted: function () {
    this.$nextTick(function () {
      this.timerFun()
    })
  },
  methods: {

    timerFun() {
      let self = this;

      this.timer = setInterval(function () {
        self.get_game();
      }, 1000);
    },

    async get_game() {
      let num;
      let uuidP;
      if (this.$route.query.uuidP != undefined) {
        uuidP= this.$route.query.uuidP ;
      }
      if (this.$route.query.game == undefined) {
        num = this.$route.query.publicId;
      } else {
        num = this.$route.query.game;
      }
      if (num == undefined) {
        return;
      }


      try {
        const response = await fetch(import.meta.env.VITE_API_LINK + '/games/' + num + '/', {
          method: 'GET',
          headers: { 'Content-type': 'application/json; charset=UTF-8' },
        });

        await response.json().then((data) => {

          data.uuidP = uuidP

          if (data.state == 2) {
            
            this.$router.push({ path: '/game-answer', query: data })
          }
          else if (data.state == 3 || data.state == 4) {


            this.$router.push({ path: '/game-start', query: data })
          }
        });
      } catch (error) {
        console.error(error);
      }


    },
  },
}
</script>
<style >
button {
  background: #009435;
  border: 1px solid #009435;
}


#app {
  width: 100vw;
  height: 100vh;
}

:root {
  --colorfondo: #da6f03;

}

body {

  background-color: var(--colorfondo) !important
}
</style>
