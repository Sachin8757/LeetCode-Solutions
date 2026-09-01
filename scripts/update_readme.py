from pathlib import Path
import re

ROOT = Path(__file__).resolve().parent.parent
README = ROOT / "README.md"

# --------------------------------------------------
# Find all C++ solution files
# --------------------------------------------------

cpp_files = list(ROOT.rglob("*.cpp"))

# Ignore files inside .git and scripts
cpp_files = [
    file for file in cpp_files
    if ".git" not in file.parts
    and "scripts" not in file.parts
]


# --------------------------------------------------
# Difficulty detection
# --------------------------------------------------

easy = 0
medium = 0
hard = 0

for file in cpp_files:

    parts = [part.lower() for part in file.parts]

    if "easy" in parts:
        easy += 1

    elif "medium" in parts:
        medium += 1

    elif "hard" in parts:
        hard += 1


total = easy + medium + hard


# --------------------------------------------------
# Detect languages
# --------------------------------------------------

languages = set()

for file in cpp_files:

    extension = file.suffix.lower()

    if extension == ".cpp":
        languages.add("C++")

    elif extension == ".py":
        languages.add("Python")

    elif extension == ".java":
        languages.add("Java")


# --------------------------------------------------
# Detect topics from file names/folders
# --------------------------------------------------

topics = set()

topic_keywords = {
    "array": "Arrays",
    "arrays": "Arrays",
    "string": "Strings",
    "strings": "Strings",
    "binary": "Binary Search",
    "search": "Binary Search",
    "linked": "Linked List",
    "list": "Linked List",
    "stack": "Stack",
    "queue": "Queue",
    "tree": "Tree",
    "graph": "Graph",
    "greedy": "Greedy",
    "hash": "Hashing",
    "map": "Hashing",
    "two": "Two Pointer",
    "pointer": "Two Pointer",
    "sliding": "Sliding Window",
    "bfs": "BFS",
    "dfs": "DFS",
    "dynamic": "Dynamic Programming",
}


for file in cpp_files:

    name = file.stem.lower()

    for keyword, topic in topic_keywords.items():

        if keyword in name:
            topics.add(topic)


# --------------------------------------------------
# README content
# --------------------------------------------------

languages_text = "\n".join(
    f"- {language}"
    for language in sorted(languages)
)

topics_text = "\n".join(
    f"- {topic}"
    for topic in sorted(topics)
)

if not topics_text:
    topics_text = "- More topics coming soon"


progress = f"""## Progress

- Easy: {easy}
- Medium: {medium}
- Hard: {hard}

**Total Solved: {total}**

## Languages

{languages_text}

## Topics Covered

{topics_text}
"""


# --------------------------------------------------
# Update README between markers
# --------------------------------------------------

start_marker = "<!-- AUTO-UPDATE-START -->"
end_marker = "<!-- AUTO-UPDATE-END -->"


if README.exists():

    content = README.read_text(encoding="utf-8")

else:

    content = "# LeetCode Solutions\n\n"


if start_marker in content and end_marker in content:

    pattern = (
        re.escape(start_marker)
        + r".*?"
        + re.escape(end_marker)
    )

    replacement = (
        start_marker
        + "\n\n"
        + progress
        + "\n"
        + end_marker
    )

    content = re.sub(
        pattern,
        replacement,
        content,
        flags=re.DOTALL
    )

else:

    content += (
        "\n"
        + start_marker
        + "\n\n"
        + progress
        + "\n"
        + end_marker
        + "\n"
    )


README.write_text(content, encoding="utf-8")

print("README.md updated successfully!")
print(f"Easy: {easy}")
print(f"Medium: {medium}")
print(f"Hard: {hard}")
print(f"Total: {total}")