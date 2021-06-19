(function($) {
    "use strict";

    // Add active state to sidbar nav links
    var path = window.location.href; // because the 'href' property of the DOM element is the absolute path
        $("#layoutSidenav_nav .sb-sidenav a.nav-link").each(function() {
            if (this.href === path) {
                $(this).addClass("active");
            }
        });

    // Toggle the side navigation
    $("#sidebarToggle").on("click", function(e) {
        e.preventDefault();
        $("body").toggleClass("sb-sidenav-toggled");
    });

    
    


})(jQuery);

function hide_show_div(hide_el, show_el) {
    var elem_hide = document.getElementById(hide_el);
    var elem_show = document.getElementById(show_el);


    elem_hide.classList.add("hidden");

    elem_show.classList.remove("hidden");
  }
