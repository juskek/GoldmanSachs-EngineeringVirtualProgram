
# Password Storage
- Password is hashed one-way and stored as an email-hash pair on a database

# Hashing Algorithms

## Encryption Focused (Slow-Hashing)
### SHA512
- 5k iterations

### bcrypt
### scrypt
### PBKDF2
## Minimal Computation (Fast-Hashing)
- Converting text to hash
### MD5
### SHA1
### SHA3

# Scenario
- Hacker gains access to database of usernames and hashed passwords
- Hacker can use hashing algorithm

# Approach
1. Assume/Identify pattern
2. Run attack with pattern rules
3. Put recovered password in a new dict
4. Repeat

# Password Patterns
## StringDigit
- String of letters followed by numbers

## loweralphanum
- lowercase
- alphanumeric only

## Capsfirst
## NumericSubs
## RandomCorrectWords

# Cracking Methods
- Hacker guesses a password, hashes it and compares it to the database
## Brute Force (takes the longest!)
- Iteratively guessing every possible combination of password
### Mask Attack
- Guessing only specific characters in each position

### Markov Attack
- Guessing only from most probable characters in each position
- 
## List of Plains/Rainbow Table
- List of plain text passwords and their hashed counterparts 

### Combinator attacks
- Combining two separate dicts
# Cracking Prevention

## Salting
- Adding random data before hashing