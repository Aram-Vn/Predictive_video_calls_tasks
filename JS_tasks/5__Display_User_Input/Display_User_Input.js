document.addEventListener('DOMContentLoaded', function() {
  const display_button = document.getElementById('display_button');
  const User_input = document.getElementById('User_input');
  const display_output = document.getElementById('display_output');

  display_button.addEventListener('click', function() {
    const input_txt = User_input.value.trim();

    if(input_txt !== '') {
        display_output.innerHTML = 'user input: ' + input_txt;
    } else {
        alert('Please enter some text before displaying.');
    }
  });

  clear_button.addEventListener('click', function() {
    User_input.value = '';
    display_output.innerHTML = '';
  })
})