#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int score;
} Player;

void writePlayer(FILE *file, Player *player) {
    fwrite(player, sizeof(Player), 1, file);
}

Player* readPlayer(FILE *file) {
    Player *player = malloc(sizeof(Player));
    if (fread(player, sizeof(Player), 1, file) != 1) {
        free(player);
        return NULL;
    }
    return player;
}

int main() {
    FILE *file = fopen("game_save.bin", "wb+");
    if (file == NULL) return 1;

    // Write players
    Player p1 = {"Alice", 100};
    Player p2 = {"Bob", 95};
    writePlayer(file, &p1);
    writePlayer(file, &p2);

    // Read specific player
    fseek(file, sizeof(Player), SEEK_SET); // Move to second player
    Player *p = readPlayer(file);
    if (p != NULL) {
        printf("Player: %s, Score: %d\n", p->name, p->score);
        free(p);
    }

    fclose(file);
    return 0;
} 