#ifndef CHIP8
#define CHIP8

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32
#define STACK_SIZE 16
#define MAX_MEMORY 4096
#define NUM_REGISTERS 16
#define FONT_SIZE 64
#define NUM_KEYS 16
#define ROM_START 0x200
#define ROM_END 0xFFF

typedef struct {
    unsigned char RAM[MAX_MEMORY];
    unsigned short stack[STACK_SIZE];

    // registers
    unsigned char V[NUM_REGISTERS];
    unsigned short program_counter;
    unsigned short index;
    unsigned short stack_pointer;

    // timers
    unsigned char delay_timer;
    unsigned char sound_timer;

    // display
    unsigned char graphics[SCREEN_WIDTH * SCREEN_HEIGHT];

    // keys
    unsigned char keyboard[NUM_KEYS];

    unsigned short current_opcode;
} Chip8;

const static uint8_t font_set[] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80, // F
};

void load_rom(Chip8 *chip8, const char* file);
void init(Chip8 *chip8);
void reset(Chip8 *chip8);
void get_opcode(Chip8 chip8);
void execute_opcode(Chip8 *chip8);
void process_user_input(Chip8 *chip8);
void update_timers(Chip8 *chip8);
#endif