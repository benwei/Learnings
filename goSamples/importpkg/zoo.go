
package main

import (
"fmt"
"./animals"
)

func zoo() {
	fmt.Printf("Welcome to zoo\n");
	animals.InstallTiger();
	animals.InstallLion();
	fmt.Printf("Enjoy!\n")
}
