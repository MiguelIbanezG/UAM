<script setup>
import GameStart from '@/components/GameStart.vue'
</script>

<template>
  <main>
    <game-start />
    

  </main>
</template>

<script>

export default {
  props: {
  },

  data() {
    return {
      timer: 0,
      active: 1,
    }
  },



  methods: {
  },

}
</script>