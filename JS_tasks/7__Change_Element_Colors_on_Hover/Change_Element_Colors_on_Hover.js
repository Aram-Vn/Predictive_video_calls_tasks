document.addEventListener("DOMContentLoaded", () => {
    const hoverable_item = document.querySelectorAll('.hoverable');

    hoverable_item.forEach(item => {
        item.addEventListener("mouseover", () => {
            item.style.color = '#ff0000';
        });
    
        item.addEventListener("mouseout", () => {
            item.style.color = '';
        });
    });
});