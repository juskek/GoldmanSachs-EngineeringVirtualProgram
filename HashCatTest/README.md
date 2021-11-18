hashcat -m 0 -a 0 -o cracked.txt target_hashes.txt rockyou.txt

-m 0 designates the type of hash we are cracking (MD5)
-a 0 designates a dictionary attack
-o cracked.txt is the output file for the cracked passwords
target_hashes.txt is our input file of hashes
rockyou.txt is the absolute path to the wordlist file for this dictionary attack

# Clear Pot