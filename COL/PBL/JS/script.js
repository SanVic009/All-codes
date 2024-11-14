// let signInButton = document.querySelector('.signInButton');
// let signUpButtonk = document.querySelector('.signUpButton');
// let namefield = document.querySelector('.namefield');

// signInButton.addEventListener('click', ()=>
// {
//     namefield.computedStyleMap.maxheight = 0;
//     signUpButton.classList.add('.disable');
//     signInButton.classList.add('.disable');
// });

// document.querySelector('input[name="password"]').addEventListener('input', function() {
//     let password = this.value;
//     let strength = 'Weak';

//     // Check password strength
//     if (password.length > 8) {
//         strength = 'Medium';
//         if (/[A-Z]/.test(password) && /[0-9]/.test(password)) {
//             strength = 'Strong';
//         }
//     }

//     // Display password strength
//     document.querySelector('#password-strength').textContent = `Password Strength: ${strength}`;
// });

document.getElementById('signupForm').addEventListener('submit', function(event) {
    let valid = true;

    // Get form field values
    let username = document.getElementById('username').value.trim();
    let email = document.getElementById('email').value.trim();
    let phone = document.getElementById('phone').value.trim();
    let password = document.getElementById('password').value.trim();
    let confirmPassword = document.getElementById('confirm-password').value.trim();

    // Validate fields are not empty
    if (username === "" || email === "" || phone === "" || password === "" || confirmPassword === "") {
        alert("All fields must be filled out.");
        valid = false;
    }

    // Validate phone number (must be 10 digits and numeric)
    if (!/^\d{10}$/.test(phone)) {
        alert("Phone number must be 10 digits.");
        valid = false;
    }

    // Validate password length and complexity
    if (password.length < 7 || !/[A-Z]/.test(password) || !/\d/.test(password) || !/[&$#@]/.test(password)) {
        alert("Password must be at least 7 characters long, contain one capital letter, one digit, and one special character from the set (&,$,#,@).");
        valid = false;
    }

    // Validate confirm password matches
    if (password !== confirmPassword) {
        alert("Passwords do not match.");
        valid = false;
    }

    // Validate email format
    let emailPattern = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,3}$/;
    if (!emailPattern.test(email)) {
        alert("Please enter a valid email address.");
        valid = false;
    }

    // Prevent form submission if any validation fails
    if (!valid) {
        event.preventDefault();
    }
});
