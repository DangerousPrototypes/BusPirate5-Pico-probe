#define BUFDIR_INPUT 0
#define BUFDIR_OUTPUT 1

void bio_init(void);
void bio_set_dir(uint8_t bio, bool dir);
void bio_set_buffer_dir(uint8_t bio, bool dir);