// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ASH_ASSISTANT_MODEL_ASSISTANT_CACHE_MODEL_OBSERVER_H_
#define ASH_ASSISTANT_MODEL_ASSISTANT_CACHE_MODEL_OBSERVER_H_

#include <map>

#include "base/macros.h"
#include "chromeos/services/assistant/public/mojom/assistant.mojom.h"

namespace ash {

// An observer which receives notification of changes to the Assistant cache.
class AssistantCacheModelObserver {
 public:
  using AssistantSuggestion = chromeos::assistant::mojom::AssistantSuggestion;

  // Invoked when the cache of conversation starters has changed.
  virtual void OnConversationStartersChanged(
      const std::map<int, const AssistantSuggestion*>& conversation_starters) {}

 protected:
  virtual ~AssistantCacheModelObserver() = default;
};

}  // namespace ash

#endif  // ASH_ASSISTANT_MODEL_ASSISTANT_CACHE_MODEL_OBSERVER_H_
