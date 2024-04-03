<script setup>
import GameJoin from '@/components/GameJoin.vue'
</script>

<template>
  <main style="top: 400px;">
    <game-join @add-participant="agregarParticipante"  />
  </main>
</template>

<script>


export default {
 
  methods: {
    async agregarParticipante(participant) {
      try {

        const response = await fetch(import.meta.env.VITE_API_LINK + '/participant/', {
          method: 'POST',
          body: JSON.stringify(participant),
          headers: { 'Content-type': 'application/json; charset=UTF-8' },
        });
        await response.json().then((data) =>
        {
          this.$router.push({path: '/game-start', query: data}) 
        });
      } catch (error) {
        console.error(error);
      }
    }
  }
}
</script>
