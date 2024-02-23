function show_hide() {
  let myDiv = document.getElementById('myDiv');
  let button = document.getElementById('hide');
  if (myDiv.style.display === 'none') {
    myDiv.style.display = 'block';
    button.innerHTML = 'Hide';
  } else {
    myDiv.style.display = 'none';
    button.innerHTML = 'Show';
  }
}
