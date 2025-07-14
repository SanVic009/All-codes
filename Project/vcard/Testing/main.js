const dropArea = document.querySelector('#dropArea')

['dragover', 'dragenter', 'dragleave', 'drop'].forEach((eventName) => {
    dropArea.addEventListener(eventName, (e) => e.preventDefault(), false)
})

['dragover', 'dragenter'].forEach((eventName) => {
    dropArea.addEventListener(eventName, () =>{
        dropArea.classList.add('highlight')
    })
})

['dragleave', 'drop'].forEach((eventName) => {
    dropArea.addEventListener(eventName, () => {
        dropArea.classList.remove('highlight');
    })
})

dropArea.addEventListener('drop', handleDrop);

const handleDrop = () => {
    
}