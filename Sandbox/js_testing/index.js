import { callPythonScript, form, inputField, resultFactorial } from './factorialSubmit.js';
import { callTesseractScript, resultDrop, dropArea} from './drop.js';

const url = 'http://localhost:3000';

dropArea.addEventListener('drop', async (e) =>{
    const res = await callTesseractScript(url, address='vcard.png')
    console.log()
})

form.addEventListener('submit', async (e) => {
    e.preventDefault();

    const number = parseInt(inputField.value);
    console.log("The number received is ", number);

    if (isNaN(number) || number <= 0) {
        alert("Enter a valid number (must be greater than 0)");
        inputField.value = '';
        return;
    }

    inputField.value = '';

    const res = await callPythonScript(url, number);
    console.log(res.factorial);

    resultFactorial.innerHTML = `<h4>The factorial of ${number} is ${res.factorial}</h4>`;
});

