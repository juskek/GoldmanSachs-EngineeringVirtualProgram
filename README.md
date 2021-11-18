# GoldmanSachs-VirtualExperienceProgram
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