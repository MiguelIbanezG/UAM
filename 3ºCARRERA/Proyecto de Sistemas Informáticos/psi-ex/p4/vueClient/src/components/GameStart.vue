<!-- src/components/GameStart.vue -->

<template >
    <br>
    <div class="fondo" style="top: 400px;">
        <p class="text-center">
                <div class="h4  text-green">
                    <p class="d-none" v-if="this.$route.query.game == undefined">{{ this.$route.query.game =
                    this.$route.query.publicId
                    }} </p>
                    Thanks for joining the game with PIN:
                    <p>{{ this.$route.query.game }}</p>
                    <p v-if="this.$route.query.state == 1">The game will start soon.</p>
                    <p v-if="this.$route.query.state == 3">The answer is shown on screen.</p>
                    <p v-if="this.$route.query.state == 4">The leaderboard is shown on screen.</p>
                </div>
            state: {{ this.$route.query.state }}
        </p>
    </div>
</template>

<script>
export default {
    name: 'game-start',
    data() {
        return {
            //
        }
    },
    methods: {
    },
    computed: {

    },
}

</script>
<style scoped >
form {
    margin-bottom: 2rem;
}
</style>