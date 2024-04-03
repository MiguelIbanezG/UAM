<!-- src/components/GameAnswer.vue -->

<template >
    <div id="answer-div" class="container-lg square-box" >
        <button v-if="this.$route.query.answers >= 1" class="btn btn-danger btn-square-lg w-50 " v-on:click="answer(0)"
            style="height: 20vh; " >
            &nbsp;
        </button>

        <div v-if="this.$route.query.answers >= 2" class="btn btn-primary btn-square-lg w-50" v-on:click="answer(1)" 
            style="height: 20vh; " >
            &nbsp;
        </div>
        <div class="w-100">

        </div>
        <div v-if="this.$route.query.answers >= 3" class="btn btn-success btn-square-lg w-50" v-on:click="answer(2)"
            style="height: 20vh; " >
            &nbsp;
        </div>

        <div v-if="this.$route.query.answers >= 4" class="btn btn-warning btn-square-lg w-50" v-on:click="answer(3)"
            style="height: 20vh; " >
            &nbsp;
        </div>
    </div>
</template>

<script>
export default {
    name: 'game-answer',
    data() {
        return {
            guess: {
                game: "",
                uuidp: "",
                answer: ""
            },
        }
    },
    el: '#answer-div',
    methods: {
        answer: function (answerid) {
            this.guess.answer = answerid
            this.guess.game = this.$route.query.publicId
            this.guess.uuidp = this.$route.query.uuidP
            this.$emit('create-guess', this.guess);
        }
    },
}


</script>
<style scoped >
form {
    margin-bottom: 2rem;
}
</style>