#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song 
{
    char name[100];
    struct Song* prev;
    struct Song* next;
};

struct Song* head = NULL;
struct Song* current = NULL;

// Function to create a new song node
struct Song* createSong(char name[]) 
{
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, name);
    newSong->prev = NULL;
    newSong->next = NULL;
    return newSong;
}

// Add song to the end of the playlist
void addSong(char name[]) 
{
    struct Song* newSong = createSong(name);

    if (head == NULL) 
    {
        head = newSong;
        current = head;
        printf("Added \"%s\" as the first song.\n", name);
        return;
    }

    struct Song* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newSong;
    newSong->prev = temp;

    printf("Added \"%s\" to the playlist.\n", name);
}

// Delete a song by name
void deleteSong(char name[]) 
{
    if (head == NULL) 
    {
        printf("Playlist is empty!\n");
        return;
    }

    struct Song* temp = head;

    while (temp != NULL && strcmp(temp->name, name) != 0)
        temp = temp->next;

    if (temp == NULL) 
    {
        printf("Song not found!\n");
        return;
    }

    if (temp == head)
        head = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp)
        current = (temp->next != NULL) ? temp->next : temp->prev;

    printf("Deleted \"%s\" from the playlist.\n", name);
    free(temp);
}

// Play next song
void playNext() 
{
    if (current == NULL) 
    {
        printf("Playlist is empty!\n");
        return;
    }

    if (current->next != NULL) 
    {
        current = current->next;
        printf("Now playing: %s\n", current->name);
    } else {
        printf("You’re at the last song!\n");
    }
}

// Play previous song
void playPrevious() 
{
    if (current == NULL) 
    {
        printf("Playlist is empty!\n");
        return;
    }

    if (current->prev != NULL) 
    {
        current = current->prev;
        printf("Now playing: %s\n", current->name);
    } else {
        printf("You’re at the first song!\n");
    }
}

// Show all songs in the playlist
void showPlaylist() 
{
    if (head == NULL) 
    {
        printf("Playlist is empty!\n");
        return;
    }

    printf("\nCurrent Playlist:\n");
    struct Song* temp = head;
    while (temp != NULL) 
    {
        if (temp == current)
            printf("-> %s (Currently Playing)\n", temp->name);
        else
            printf("   %s\n", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    int choice;
    char songName[100];

    do {
        printf("\n====== MUSIC PLAYLIST MANAGER ======\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Play Next Song\n");
        printf("4. Play Previous Song\n");
        printf("5. Show Playlist\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline

        switch (choice) 
        {
        case 1:
            printf("Enter song name: ");
            fgets(songName, sizeof(songName), stdin);
            songName[strcspn(songName, "\n")] = '\0'; // remove newline
            addSong(songName);
            break;

        case 2:
            printf("Enter song name to delete: ");
            fgets(songName, sizeof(songName), stdin);
            songName[strcspn(songName, "\n")] = '\0';
            deleteSong(songName);
            break;

        case 3:
            playNext();
            break;

        case 4:
            playPrevious();
            break;

        case 5:
            showPlaylist();
            break;

        case 6:
            printf("Exiting Playlist Manager...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
