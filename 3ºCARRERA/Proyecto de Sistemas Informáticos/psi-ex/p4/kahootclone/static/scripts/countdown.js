function refresh() {
    $.ajax({
        url: "{% url 'game-count-down' %}", 
        success: function (data) {
            $('#countdown').html(data);
        }
    });
}


$(document).ready(function () {
    console.log("setting interval");
    setInterval(refresh, 1000);
});