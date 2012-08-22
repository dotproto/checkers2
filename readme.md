I wanted to start over with a clean slate and try to focus on the interface rather than the implementation. To that end, I created a new repository and started specing out what structures and classes I would need to create. This work was done in `objects.h`.

After a bit I began to roadblock on the interface design as my mind wasn't able to see into the future enough to know what objects I'd need to create. In order to address this, I decided to start fleshing out one aspect of the implementation that I was pretty clear on: drawing the board. I had some code that handled most of the heavy lifting, but I wanted to adapt it to be more readable in my eyes and to support Win/Linux. I may have done more there, but I'm not 100%.

This commit represents what I was able to accomplish so far. I happen to have a better dev environment set up in my Ubuntu VM, so I've been focusing on building on Linux.

    g++ -Wall hello.cpp objects.h game.cpp
