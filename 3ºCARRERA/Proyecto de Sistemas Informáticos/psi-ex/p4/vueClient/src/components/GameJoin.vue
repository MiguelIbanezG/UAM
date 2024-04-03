<!-- src/components/GameJoin.vue -->

<template >
    <div id="game-join" class="text-center fondo">
        <br>
        <p class="h1 text-green">Join Kahoot Game</p>
        <div class="container-sm">

            <form @submit.prevent="enviarFormulario">
                <div class="row">
                    <div class="col ">
                        <div class="form-group">
                            <input v-model="participant.alias" type="text" placeholder="Enter your alias"
                                class="form-control form-control-sm" :class="{ 'is-invalid': procesando && nombreInvalido }"
                                @focus="resetEstado" />
                        </div>
                    </div>
                </div>
                <div class="col">
                    <div class="mt-2">

                    </div>
                </div>
                <div class="col ">
                    <div class="form-group text-center">
                        <input v-model="participant.game" type="number" placeholder="Enter game ID"
                            class="form-control form-control-sm" :class="{ 'is-invalid': procesando && numeroInvalido }"
                            @focus="resetEstado" />
                    </div>
                </div>
                &nbsp;
                <div class="col">
                    <div class="form-group">
                        <button class="btn btn-primary">Submit</button>
                    </div>
                </div>
                <div class="col ">
                    <div v-if="error && procesando" class="alert alert-danger" role="alert">
                        Debes rellenar correctamente todos los campos!
                    </div>
                    <div v-if="correcto" class="alert alert-success" role="alert">
                        La persona ha sido agregada correctamente!
                    </div>
                </div>
            </form>
        </div>
    </div>
</template>

<script>
export default {
    name: 'game-join',
    data() {
        return {
            procesando: false,
            correcto: false,
            error: false,
            participant: {
                alias: '',
                game: '',
            },
        }
    },
    methods: {
        enviarFormulario() {
            this.procesando = true;
            if (this.nombreInvalido || this.numeroInvalido || this.campoVacio) {
                this.error = true;
                return;
            }
            this.$emit('add-participant', this.participant);
            this.error = false;
            this.correcto = true;
            this.procesando = false;

            this.participant = {
                alias: '',
                game: '',
            }
        },
        resetEstado() {
            this.correcto = false;
            this.error = false;
        }
    },
    computed: {
        nombreInvalido() {
            return this.participant.alias.length < 1;
        },
        numeroInvalido() {
            return this.participant.game < 1;
        },
        campoVacio() {
            return this.participant.alias.length == " ";
        },
    },
}

</script>
<style scoped>
form {
    margin-bottom: 2rem;
}

</style>