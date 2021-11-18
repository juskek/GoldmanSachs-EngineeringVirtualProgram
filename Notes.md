# 1. Tracker
## 1.1. Uncracked

## 1.2. Cracked
### 1.2.1. Dict Attack: rockyou.txt
hashcat -m 0 -a 0 -o cracked.txt PasswordHashes.txt dicts/rockyou.txt
- MD5 dictionary attack
```
edi_tesla89:6c569aabbf7775ef8fc570e228c16b98:password!
liveltekah:3f230640b78d7e71ac5514e57935eb69:qazxsw
experthead:e10adc3949ba59abbe56e057f20f883e:123456
interestec:25f9e794323b453885f5181f1b624d0b:123456789
reallychel:5f4dcc3b5aa765d61d8327deb882cf99:password
eatingcake1994:fcea920f7412b5da7be0cf42b8c93759:1234567
bookma:25d55ad283aa400af464c76d713c07ad:12345678
popularkiya7:e99a18c428cb38d5f260853678922e03:abc123
ortspoon:d8578edf8458ce06fbc5bb76a58c5ca4:qwerty
simmson56:96e79218965eb72c92a549dd5a330112:111111
heroanhart:7c6a180b36896a0a8c02787eeafb0e4c:password1
johnwick007:f6a0cb102c62879d397b12b62c092c06:bluered
blikimore:917eb5e9d6d6bca820922a0c6f7cc28b:Pa$$word1
```
FINDINGS: 
- minimum length is 6
- max length so far is 9
- uppercase is not required
- numbers are not required
### 1.2.2. Dict Attack: top10mil.txt
hashcat -m 0 -a 0 -o cracked.txt PasswordHashes.txt dicts/top10mil.txt
NO NEW CRACKS

### 1.2.3. Mask Attack: lowercase


6: hashcat -m 0 -a 3 PasswordHashes.txt "?l?l?l?l?l?l"
7: hashcat -m 0 -a 3 PasswordHashes.txt "?l?l?l?l?l?l?l"
8: hashcat -m 0 -a 3 PasswordHashes.txt "?l?l?l?l?l?l?l?l"
9: hashcat -m 0 -a 3 PasswordHashes.txt "?l?l?l?l?l?l?l?l?l"
NO NEW CRACKS

### 1.2.4. Mask Attack: uppercase
6: hashcat -m 0 -a 3 PasswordHashes.txt "?u?u?u?u?u?u"
7: hashcat -m 0 -a 3 PasswordHashes.txt "?u?u?u?u?u?u"
8: hashcat -m 0 -a 3 PasswordHashes.txt "?u?u?u?u?u?u"
9: hashcat -m 0 -a 3 PasswordHashes.txt "?u?u?u?u?u?u"
NO NEW CRACKS

### 1.2.5. Mask Attack: x lower + y numbers
x4y2: hashcat -m 0 -a 3 PasswordHashes.txt "?l?l?l?l?d?d"
x5y2: hashcat -m 0 -a 3 PasswordHashes.txt "?l?l?l?l?l?d?d"
NO NEW CRACKS

x6y2: hashcat -m 0 -a 3 PasswordHashes.txt "?l?l?l?l?l?l?d?d"
```
moodie:8d763385e0476ae208f21bc63956f748:moodie00
```
FINDINGS: 
- password for this user is the username and two numbers

### 1.2.6. Hybrid Dictionary + Mask Attack: username + y numbers
usernameYY: hashcat -m 0 PasswordHashes.txt -a 6 lowercaseUsernames.txt "?d?d"
usernameYYYY: hashcat -m 0 PasswordHashes.txt -a 6 lowercaseUsernames.txt "?d?d?d?d"

UsernameYY: hashcat -m 0 PasswordHashes.txt -a 6 titlecaseUsernames.txt "?d?d"
```
spuffyffet:1f5c5683982d7c3814d4d9e6d749b21e:Spuffyffet12
```
UsernameYYYY: hashcat -m 0 PasswordHashes.txt -a 6 titlecaseUsernames.txt "?d?d?d?d"
```
oranolio:16ced47d3fc931483e24933665cded6d:Oranolio1994
```
FINDINGS:
- These passwords are just the username titlecased with two/four additional numbers, which is a common number of digits to add to represent some year

### 1.2.7. Rule Based: Titlecased username
Username: hashcat -m 0 PasswordHashes.txt -a 0 titlecaseUsernames.txt
```
flamesbria2001:9b3b269ad0a208090309f091b3aba9db:Flamesbria2001
```

### 1.2.8. Replacing characters with symbols
Common substitutions:
$, S or 5 for s
1, I or ! for i
1 or ! for l
@ or A for a
7 or T for t
3 or E for e
9, G or 6 for g
0 or O for o
8 or B for b

Remaining usernames: bandalls, nabox

- Replace usernames
hashcat -m 0 PasswordHashes.txt -a 0 lowercaseUsernames.txt -r rules.txt
usernameReplaceds5: ss5
usernameReplacedS$: sS$
usernameReplaceda@: sa@
usernameReplacedaA: saA
usernameReplacedo0: so0
usernameReplacedoO: soO
usernameReplacedb8: sb8
usernameReplacedbB: sbB
usernameReplacedl1: sl1

Usernamereplaceds5: ss5 c
Usernamereplaceds$: sS$ c
Usernamereplaceda@: sa@ c
Usernamereplacedaa: saA c
Usernamereplacedo0: so0 c
Usernamereplacedoo: soO c
Usernamereplacedb8: sb8 c
Usernamereplacedbb: sbB c
Usernamereplacedl1: sl1 c
```
bandalls:bdda5f03128bcbdfa78d8934529048cf:Banda11s
```
### 1.2.9. Dive Ruleset
hashcat -m 0 PasswordHashes.txt -a 0 lowercaseUsernames.txt -r rules/dive.rule
NO NEW CRACKS

### 1.2.10. NSAKEY Ruleset
hashcat -m 0 PasswordHashes.txt -a 0 lowercaseUsernames.txt -r rules/nsakey.rule
NO NEW CRACKS

### 1.2.11. Mask: Brute Force all characters
6: hashcat -m 0 -a 3 PasswordHashes.txt "?a?a?a?a?a?a"
7: hashcat -m 0 -a 3 PasswordHashes.txt "?a?a?a?a?a?a?a"
```
nabox:defebde7b6ab6f24d5824682a16c3ae4:nAbox!1
```
# 2. Email Memo 
Dear XXX,

Hope your week has gone well. 

As requested, I have reviewed the security level of passwords from the leaked database and have arrived at the following findings:
- Hashing Algorithm: MD5
- Cracked Passwords: 19/19 (100%)
- Keyspace: Uppercase, lowercase, numbers, symbols
- Most common password formats:
  - Series of numbers, e.g., 12345
  - Variation of "password", e.g., password!, Pa$$word1
  - Series of characters forming a pattern, e.g., qwerty, qazxsw, abc123
  - Variation of their username with trailing numbers, e.g., Username1993, username2001, 
  - Replacing characters in username with numbers and symbols, e.g., Banda11s

In light of these results, there are a few points which I would like to raise for discussion:
1. MD5 is an insecure hashing algorithm. It was originally designed for converting plaintext into hashes with a minimal amount of computation. As such, randomly guessing all possible combinations of a password becomes realistic, e.g., it took three hours for me to go through all possible permutations of a 7-character password on my laptop. Furthermore, there is a growing online list of MD5 hashes and their plain text equivalents, decreasing the security of shorter MD5 passwords.
- Recommendation: 
  - Utilise a more secure hashing algorithm, e.g., SHA512crypt which passes text through 5,000 hashing iterations, discouraging brute force cracking. 
  - Check whether the password has already been cracked for the implemented hash by utilising an online tool (e.g., https://www.security.org/how-secure-is-my-password/).
2. Insufficient password length. Most of the passwords are between 6-10 characters long, which still allows some extent of brute force cracking, regardless of the hashing standard used.
- Recommendation: 
  - Increase the minimum password length to 10 characters as opposed to 6. This increases the theoretical time to crack a password by brute force from 8 hours to 5 years (as measured by https://www.security.org/how-secure-is-my-password/).
3. Commonly used password formats. Regardless of how many characters there are in a password, the theoretical time taken to crack it will be redundant if the password follows some sort of pattern.
- Recommendation:
  - Discourage users from using passwords which follow common formats, as listed above.
  - Encourage the use of randomly generated passwords.

These recommendations should thwart attackers in the event of a password leak, but do not serve as an immutable guide since security risks are evolving. I suggest scheduling a regular review of the password policies and hashing standards used, alongside database protection. 

Please let me know if you have any questions; in the meantime I will look into the specifics of designing a technical implementation of the recommended policy changes.


Best Regards,
Justin




Leaked hashes and their plains, in order of decryption.
- Passwords cracked from RockYou leak, time taken: negligible.
edi_tesla89:6c569aabbf7775ef8fc570e228c16b98:password!
liveltekah:3f230640b78d7e71ac5514e57935eb69:qazxsw
experthead:e10adc3949ba59abbe56e057f20f883e:123456
interestec:25f9e794323b453885f5181f1b624d0b:123456789
reallychel:5f4dcc3b5aa765d61d8327deb882cf99:password
eatingcake1994:fcea920f7412b5da7be0cf42b8c93759:1234567
bookma:25d55ad283aa400af464c76d713c07ad:12345678
popularkiya7:e99a18c428cb38d5f260853678922e03:abc123
ortspoon:d8578edf8458ce06fbc5bb76a58c5ca4:qwerty
simmson56:96e79218965eb72c92a549dd5a330112:111111
heroanhart:7c6a180b36896a0a8c02787eeafb0e4c:password1
johnwick007:f6a0cb102c62879d397b12b62c092c06:bluered
blikimore:917eb5e9d6d6bca820922a0c6f7cc28b:Pa$$word1
- Password cracked from x lowercase characters and y trailing numbers, time taken: negligible.
moodie:8d763385e0476ae208f21bc63956f748:moodie00

- Password cracked from a variation of usernames and y trailing numbers, time taken: negligible. 
spuffyffet:1f5c5683982d7c3814d4d9e6d749b21e:Spuffyffet12
oranolio:16ced47d3fc931483e24933665cded6d:Oranolio1994
flamesbria2001:9b3b269ad0a208090309f091b3aba9db:Flamesbria2001

- Password cracked from replacing characters in username, time taken: negligible.
bandalls:bdda5f03128bcbdfa78d8934529048cf:Banda11s

- Password cracked from brute force, time taken: 3 hours.
nabox:defebde7b6ab6f24d5824682a16c3ae4:nAbox!1


# 3. What type of hashing algorithm was used to protect passwords?
Each of the hashes are 32 characters, which leads me to suspect that the hashing algorithm is the commonly used MD5, since it is a 128-bit hash function which produces 32 hexadecimal digits. However, other algorithms which produce 32 digit hashes include MD2, MD4, haval

It should be noted that a 32 character hash does not indicate the use of the aforementioned algorithms, since the hash 
-  could be produced by a longer encryption algorithm but stored in a 32-character field, or 
-  could be produced by concatenating two or more shorter hashing functions.

To determine whether an MD5 algorithm was used, HashCat was used to brute force commonly used passwords against the provided hashes. The following attacks were used to crack

Stage 1
- Hash: MD5
- Attack: Dictionary
  - Dictionary used was a wordlist of over 14 million passwords from the RockYou exposure in 2009
- Cracked: 13/19
```
6c569aabbf7775ef8fc570e228c16b98:password!
3f230640b78d7e71ac5514e57935eb69:qazxsw
e10adc3949ba59abbe56e057f20f883e:123456
25f9e794323b453885f5181f1b624d0b:123456789
5f4dcc3b5aa765d61d8327deb882cf99:password
fcea920f7412b5da7be0cf42b8c93759:1234567
25d55ad283aa400af464c76d713c07ad:12345678
e99a18c428cb38d5f260853678922e03:abc123
d8578edf8458ce06fbc5bb76a58c5ca4:qwerty
96e79218965eb72c92a549dd5a330112:111111
7c6a180b36896a0a8c02787eeafb0e4c:password1
f6a0cb102c62879d397b12b62c092c06:bluered
917eb5e9d6d6bca820922a0c6f7cc28b:Pa$$word1
```
- Remarks:
  - This confirms that the hashing algorithm used was MD5. A majority of the passwords were captured
Stage 2
- Hash: MD5
- Attack: 

# 4. What level of protection does the mechanism offer for passwords?
# 5. What controls could be implemented to make cracking much harder for the hacker in the event of a password database leaking again?
# 6. What can you tell about the organization’s password policy (e.g. password length, key space, etc.)?
# 7. What would you change in the password policy to make breaking the passwords harder? 