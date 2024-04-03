<script setup>
import { RouterLink, RouterView } from "vue-router";
</script>
<template>
  <div>
    <h1>Ejemplo de uso de Router</h1>
    <router-view></router-view>
    <a class="button"
      ><router-link to="/page-one">Click for Page 1</router-link></a
    >&nbsp;
    <a class="button"
      ><router-link to="/page-two">Click for Page 2</router-link></a
    >
  </div>
</template>
<script>
export default {};
</script>