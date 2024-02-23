document.addEventListener('DOMContentLoaded', function() {

    let change_button = document.getElementById('change_button');
    let text_paragraph = document.getElementById('text_paragraph');

    const text_arr = ['start!','Text 1', 'Text 2', 'Text 3', 'end!!!'];
    let cur_ind = 0;

    change_button.addEventListener('click', function() {
        text_paragraph.textContent = text_arr[cur_ind];

        cur_ind = (cur_ind + 1) % text_arr.length;
    });
});