function show_hide() {
  let p = document.getElementById('poxel')
  let button = document.getElementById('hide')
  if (p.style.display === 'none') {
    p.style.display = 'block';
    button.innerHTML = 'Hide';
  }
  else {
    p.style.display = 'none';
    button.innerHTML = 'show';
  }
}