#!/usr/bin/env python3

from collections import defaultdict

def get_unalloted_users(bids, total_shares):
    alloted = set()

    by_bid = defaultdict(list)
    for bid in bids:
        by_bid[bid[2]].append(bid)

    highest_bids = sorted(by_bid, reverse=True)

    for bid in highest_bids:
        curr_bids = sorted(by_bid[bid], key=lambda x: x[3])

        # One highest bidder
        if len(curr_bids) == 1:
            total_shares -= curr_bids[0][1]
            alloted.add(curr_bids[0][0])
            continue

        # Multiple highest bidders
        idx = 0
        remaining = len(curr_bids)
        while remaining > 0 and idx <= len(curr_bids):
            if idx == len(curr_bids):
                idx = 0

            if curr_bids[idx][1] > 0:
                curr_bids[idx][1] -= 1

                if curr_bids[idx][1] == 0:
                    remaining -= 1

                alloted.add(curr_bids[idx][0])
                total_shares -= 1

            if total_shares <= 0:
                break

            idx += 1

        if total_shares <= 0:
            break

    return list({x[0] for x in bids if x[0] not in alloted})


print(get_unalloted_users([[1, 5, 5, 0], [2, 7, 8, 1], [3, 7, 5, 1], [4, 10, 3, 3]], 18))
