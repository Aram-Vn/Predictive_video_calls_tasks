document.addEventListener('DOMContentLoaded', () => {
    const tabs = document.querySelectorAll('.tab');
    const contents = document.querySelectorAll('.content');

    const tab_content = {
        tab1: "some text",
        tab2: "some more text",
        tab3: "again just a text",
    };

    tabs.forEach(tab => {
        tab.addEventListener('click', () => {
            const tab_id = tab.id;
            const content_id = tab_id.replace('tab', 'content');

            tabs.forEach(t => t.classList.remove('active'));
            contents.forEach(c => c.classList.remove('active'));

            tab.classList.add('active');
            document.getElementById(content_id).classList.add('active');
            document.getElementById(content_id).textContent = tab_content[tab_id];
        });
    });
});