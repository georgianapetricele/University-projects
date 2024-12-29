# Implementation of permutation cipher
def permutation_cipher(message: str, permutation_key: str, decrypt: bool = False):
    key_length = len(permutation_key)
    message_length = len(message)
    result = ""

    # Add spaces to the end if the message length can't be divided exactly by the key length
    padding_needed = (key_length - (message_length % key_length)) % key_length
    message += ' ' * padding_needed
    message_length = len(message)

    nr_blocks = int(message_length / key_length)  # Total number of blocks

    encrypted_message = ""
    for i in range(nr_blocks):
        # processing current block
        start_index = i * key_length
        block = message[start_index:(start_index + key_length)]
        encrypted_message_block = [' '] * key_length

        for index in range(key_length):
            new_index = int(permutation_key[index]) - 1

            if decrypt:
                encrypted_message_block[new_index] = block[index]  # for decryption reverse the permutation
            else:
                encrypted_message_block[index] = block[new_index]  # for encryption reverse the characters on the indexes of permutation and message indexes

        encrypted_message += ''.join(encrypted_message_block)

        final_message = encrypted_message.strip(' ')

    return final_message


message = "computational"
permutation_key = "24531"

# Encrypt the message
encrypted_message = permutation_cipher(message, permutation_key, False)

# Decrypt the message
decrypted_message = permutation_cipher(encrypted_message,permutation_key,True)


print("Encrypted message is ",encrypted_message)
print("Decrypted message is ",decrypted_message)
