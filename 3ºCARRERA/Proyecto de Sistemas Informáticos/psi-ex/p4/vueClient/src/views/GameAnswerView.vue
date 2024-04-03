<script setup>
import GameAnswer from '@/components/GameAnswer.vue'
</script>

<template>
  <main style="top: 400px;">
    <game-answer @create-guess="createGuess"/>
  </main>
</template>

<script>

export default {
  methods: {
        
    async createGuess(guess) {
      try {
        const response = await fetch(import.meta.env.VITE_API_LINK + '/guess/', {
          method: 'POST',
          body: JSON.stringify(guess),
          headers: { 'Content-type': 'application/json; charset=UTF-8' },
        });
        await response
        this.$route.query.answered == true
          this.$router.push({path: '/game-answer', query: this.$route.query}) 
      } catch (error) {
        console.error(error);
      }
    }
      }

  }

</script>

