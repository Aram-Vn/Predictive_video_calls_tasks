document.addEventListener("DOMContentLoaded", () => {
    const sliderImage = document.getElementById('sliderImage');
    const prevBtn = document.getElementById('prevBtn');
    const nextBtn = document.getElementById('nextBtn');

    const imageArray = [
        './images/image1.jpeg',
        './images/image2.jpeg',
        './images/image3.jpeg'
    ];

    let currentIndex = 0;

    function updateImage() {
        sliderImage.src = imageArray[currentIndex];
    }

    nextBtn.addEventListener('click', () => {
        currentIndex = (currentIndex + 1) % imageArray.length;
        updateImage();
    });

    prevBtn.addEventListener('click', () => {
        currentIndex = (currentIndex - 1 + imageArray.length) % imageArray.length;
        updateImage();
    });

    updateImage();
});
