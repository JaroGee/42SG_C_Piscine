# BSQ Defense & Practice Companion

This guide expands on your existing walkthrough with fresh drills, whiteboard prompts, and quick-reference tables you can keep open during a mock defense.

## 1. Rapid Recap Checklist
- [ ] Re-state the map format and validation sequence without notes.
- [ ] Explain the scanning algorithm in <60 seconds.
- [ ] Mention tie-breaking (top-most, then left-most) and why it works automatically.
- [ ] Call out the only system calls you use.
- [ ] Describe one limitation and one possible improvement.

Use this as a pre-defense warm-up: if any box is hard to tick, skim the corresponding section below.

## 2. Drill Problems
Try these without compiling first; once you have a mental answer, implement and run.

### Drill A — Ragged map rejection
```
5.ox
.....
....o
.....
.....
```
*Expected outcome*: `map error` because the second data row is shorter than the first.

### Drill B — Edge-filled solution
```
6.oX
......
.oooo.
.oooo.
.oooo.
.oooo.
......
```
*Prompt*: Predict the coordinates (row/col) and size of the largest square before running. Confirm the solver keeps the 2×2 block at the bottom-right.

### Drill C — Streaming stdin
1. Start your program with `cat drill.map | ./bsq`.
2. Hit Ctrl+D to close stdin and make sure the solver still produces the filled map.

### Drill D — Stress the allocator
Generate a 30×30 empty map and confirm runtime remains snappy even with the naive frontier scan. Optional: measure with `/usr/bin/time -p`.

## 3. Viva-style Q&A Extensions
- **What happens if the header declares more rows than provided?**
  - Your parser stops when it runs out of lines, notices you populated fewer rows than `map->row`, and prints `map error`. Mention this explicitly.
- **Could you reuse buffers instead of reallocating in `append_content`?**
  - Yes: explain that doubling the buffer size would improve amortized complexity. State it as a potential refactor, not something you implemented.
- **How would you add diagonal scanning for a variant problem?**
  - Sketch converting the frontier check into a helper that receives direction vectors; show you understand modularization.

## 4. Comparison: Naive Frontier vs Dynamic Programming
| Aspect | Frontier Growth (current) | DP Approach |
| --- | --- | --- |
| Time complexity | ~O(R·C·S) | O(R·C) |
| Memory | O(1) extra | O(R·C) extra (if you store a second grid) |
| Code size | Small, easy to keep Norm compliant | Slightly longer, requires bookkeeping of neighbors |
| Debugging | Straightforward: watch square grow | Must inspect DP matrix |

Keep this table handy if a peer asks "Why not DP?" — you can answer in a few seconds.

## 5. Micro-scripts for Quick Testing
```bash
# Build
make

# Run a single file and show errors distinctly
./bsq ok1.map || echo "(program exited non-zero)"

# Batch-run mixed inputs with blank line separation already handled by main.c
./bsq ok1.map bad_header.map tiny.map

# Time a big empty map
python3 - <<'PY'
rows = 30
print(f"{rows}.ox")
for _ in range(rows):
    print("." * rows)
PY | /usr/bin/time -p ./bsq
```
These commands reinforce muscle memory for the required workflow.

## 6. Flash Answers (Memorize)
- **Allowed syscalls?** `open`, `read`, `write`, `close`, `malloc`, `free`, `exit`.
- **How do you ensure newline handling?** `ft_strlen_d` stops at `\n`, giving you precise column counts.
- **Where do you free allocations?** `ft_free_map` iterates rows, frees each, then the row array, then the `t_map` struct.
- **Tie-breaking guarantee?** Outer loops scan row-major, and you update only on strictly larger squares.

Rehearse these aloud; the goal is to answer in under five seconds each.

## 7. Next Improvements (if asked "what’s next?")
1. Swap the frontier scan for DP to achieve O(R·C) runtime on very large maps.
2. Add unit-style tests that feed known maps and assert outputs, using the same binary.
3. Implement a buffer-doubling reader to avoid repeated reallocations for big files.

Mentioning these shows you have forward-looking ideas without undermining the current submission.
