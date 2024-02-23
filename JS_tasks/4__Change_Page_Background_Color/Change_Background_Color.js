document.addEventListener('DOMContentLoaded', function() {
  const colorButtons = document.querySelectorAll('.color-button');

  colorButtons.forEach(function(button) {
    button.addEventListener('click', function() {
      let color = button.innerHTML.toLowerCase();

      if (color === 'reset') {
        color = 'darkgray';
      }

      document.body.style.backgroundColor = color;
    });
  });
});