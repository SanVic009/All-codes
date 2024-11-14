document.getElementById('registrationForm').addEventListener('submit', function(event) {
    event.preventDefault();

    const username = document.getElementById('username').value.trim();
    const email = document.getElementById('email').value.trim();
    const phone = document.getElementById('phone').value.trim();
    const password = document.getElementById('password').value;
    const confirmPassword = document.getElementById('confirmPassword').value;

    // Check if any field is empty
    if (!username || !email || !phone || !password || !confirmPassword) {
        alert('All fields must be filled out.');
        return;
    }

    // Phone number validation (10 digits)
    if (!/^\d{10}$/.test(phone)) {
        alert('Phone number must be exactly 10 digits.');
        return;
    }

    // Password validation
    if (!/(?=.[A-Z])(?=.\d)(?=.*[&$#@]).{7,}/.test(password)) {
        alert('Password must be at least 7 characters long, with at least one uppercase letter, one digit, and one special character (&, $, #, @).');
        return;
    }

    // Passwords match
    if (password !== confirmPassword) {
        alert('Passwords do not match.');
        return;
    }

    // Email validation
    if (!/^[^\s@]{3,}@.{3,}\.[a-zA-Z]{2,3}$/.test(email)) {
        alert('Invalid email format. It must contain "@" and "." with appropriate characters.');
        return;
    }

    alert('Form submitted successfully!');
});