const vscode = acquireVsCodeApi();

function initializeComponents() {
    console.log("Initializing components...");

    // Set up resizer
    const resizer = document.getElementById('resizer');
    const sidebar = document.querySelector('.sidebar');
    if (resizer && sidebar) {
        let isResizing = false;

        resizer.addEventListener('mousedown', function(e) {
            console.log("Resizer mousedown");
            isResizing = true;
            resizer.classList.add('dragging');
            document.body.style.cursor = 'col-resize';
            document.body.style.userSelect = 'none';
            e.preventDefault();
        });

        document.addEventListener('mousemove', function(e) {
            if (!isResizing) return;
            console.log("Resizer mousemove");

            const containerRect = document.querySelector('.container').getBoundingClientRect();
            const newWidth = e.clientX - containerRect.left;

            if (newWidth > 200 && newWidth < 500) {
                sidebar.style.width = newWidth + 'px';
            }
        });

        document.addEventListener('mouseup', function() {
            if (isResizing) {
                console.log("Resizer mouseup");
                isResizing = false;
                resizer.classList.remove('dragging');
                document.body.style.cursor = '';
                document.body.style.userSelect = '';
            }
        });
    }

    // Set up contact item click handlers
    const contactItems = document.querySelectorAll('.contact-item');
    console.log("Found " + contactItems.length + " contact items");
    contactItems.forEach(item => {
        item.addEventListener('click', function(e) {
            console.log("Contact item clicked:", item.textContent);
            // Remove active class from all items
            contactItems.forEach(i => {
                i.classList.remove('active');
            });

            // Add active class to clicked item
            item.classList.add('active');

            // Send message to extension
            const url = item.getAttribute('data-url');
            console.log("Sending message to VSCode with URL:", url);
            vscode.postMessage({
                command: 'openAIWebsite',
                url: url
            });
        });
    });
}

// Wait for DOM to be fully loaded
if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initializeComponents);
} else {
    setTimeout(initializeComponents, 100); // Small delay to ensure DOM is ready
}