import sysv_ipc

#Create a key
key = 12

# Create shared memory object
memory = sysv_ipc.SharedMemory(key)

# Read value from shared memory
memory_value = memory.read()
print memory_value

#Putting those values in a lsit
encoder_str = []
encoder_str = memory_value.split('\0')
encoder_str = filter(None , encoder_str)

#Convert str into list of integr
encoder_val = []
encoder_val = map(int, encoder_str)
print encoder_val