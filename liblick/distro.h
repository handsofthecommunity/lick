/**
 * @file
 * @brief Picks the kernel, initrd and options for a given distro
 */

// TODO: more distributions

#pragma once

#include "lickdir.h"
#include "llist.h"

/**
 * @brief Distribuion IDs
 */
typedef enum {
    DISTRO_PUPPY = 1,
    DISTRO_FATDOG = 2,
} distro_e;

/**
 * @brief Information taken from a list of files
 */
typedef struct distro_info_t {
    /// a human-readable name
    char *name;
    /// the path to the kernel
    char *kernel;
    /// the path to the initrd
    char *initrd;
    /// options to pass to the kernel
    char *options;
    /// if a more advanced setup is needed, put the entire menu section here
    char *full_text;
} distro_info_t;

/**
 * @brief Free a distro_info_t and all resources associated with it
 */
void free_distro_info(distro_info_t *d);

typedef distro_info_node_t *(*distro_info_f)(string_node_t *files, const char *dst,
        const char *name, lickdir_t *lick); // TODO: menu type
typedef int (*distro_filter_f)(const char *f);

/**
 * @brief Information about a distribution
 */
typedef struct distro_t {
    /// a numeric identifier
    distro_e id;
    /// a string identifier
    const char *key;
    /// a human-readable name
    const char *name;
    /// hook for getting menu entry information
    distro_info_f info;
    /// hook for filtering files
    distro_filter_f filter;
} distro_t;

/**
 * @brief Get a distro_t from its numberic id
 *
 * @return the corresponding distro_t if found, or NULL
 */
distro_t *get_distro(distro_e distro);
/**
 * @brief Get a distro_t from its string identifier
 *
 * @return the corresponding distro_t if found, or NULL
 */
distro_t *get_distro_by_key(const char *key);
/**
 * @brief Free a distro_t and all resources associated with it
 */
void free_distro(distro_t *d);

/**
 * @brief Get all distributions
 *
 * @return a list of distro_t
 */
distro_node_t *get_all_distros();
/**
 * @brief converts path to a grub-friendly path
 *
 * @param path The path to convert. This parameter is mutated
 * @return A pointer to the mutated path
 */
char *menu_path(char *path);
