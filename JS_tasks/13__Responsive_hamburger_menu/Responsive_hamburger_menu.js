document.addEventListener('DOMContentLoaded', () => {
    const menu_icon = document.getElementById('menuIcon');
    const nav_list = document.getElementById('navList');

    menu_icon.addEventListener('click', ()  => {
        nav_list.classList.toggle('show');
    });
});
