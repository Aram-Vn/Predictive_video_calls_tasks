function validateEmail() 
{
  const email_input = document.getElementById('email').value;

  const email_regex = /\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b/;

  if (email_input === '') 
  {
    alert('Please enter an email address')
  } 
  else if (!email_regex.test(email_input)) 
  {
    alert('Please enter a valid email address\nfor example`\nyour_email@example.com');
  }
  else
  {
    alert('Email address entered: ' + email_input);
  }
}