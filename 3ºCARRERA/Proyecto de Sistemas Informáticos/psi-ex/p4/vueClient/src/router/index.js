import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../views/HomeView.vue'
import GameJoin from '../views/GameJoinView.vue'
import GameStart from '../views/GameStartView.vue'
import GameAnswer from '../views/GameAnswerView.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'game-join',
      component: GameJoin,


    },
    {
      path: '/game-start',
      name: 'game-start',
      component: GameStart,

    },
    {
      path: '/game-answer',
      name: 'game-answer',
      component: GameAnswer,

    }
  ]
})

export default router
