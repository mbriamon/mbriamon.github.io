document.addEventListener('DOMContentLoaded', function() {
    // Event Listener for "Read More" Button
    document.getElementById('more-info').addEventListener('click', function() {
        var additionalInfo = document.getElementById('additional-info');
        additionalInfo.style.display = (additionalInfo.style.display === 'none') ? 'block' : 'none';
    });
});
