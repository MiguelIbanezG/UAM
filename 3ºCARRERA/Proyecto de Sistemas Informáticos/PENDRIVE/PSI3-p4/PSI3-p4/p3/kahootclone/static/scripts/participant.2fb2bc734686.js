function refresh() {
    $.ajax({
        url: "{% url 'game-updateparticipant' publicid=request.session.publicId %}",
        success: function (data) {
            $('#participants').html(data);
        }
    });
}


$(document).ready(function () {
    console.log("setting interval");
    setInterval(refresh, 1000);
});