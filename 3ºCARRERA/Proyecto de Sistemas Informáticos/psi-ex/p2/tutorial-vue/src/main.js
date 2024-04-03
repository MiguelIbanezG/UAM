import { createApp } from 'vue'
import App from './App.vue'
// you may want to clean default main.css file
// since default options may no satisfy you.
//import './assets/main.css'
createApp(App).mount('#app')
// the two next lines will make bootstrap available to your
// application if bootstrap has been installed.
// Instalation instructions are available later in this guide
import "../node_modules/bootstrap/dist/js/bootstrap.js"
import '../node_modules/bootstrap/dist/css/bootstrap.min.css'
