// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IOS_WEB_WEB_STATE_WEB_FRAME_IMPL_H_
#define IOS_WEB_WEB_STATE_WEB_FRAME_IMPL_H_

#include "ios/web/public/web_state/web_frame.h"

#include <string>

#include "base/macros.h"
#include "crypto/symmetric_key.h"
#include "url/gurl.h"

namespace web {

class WebState;

class WebFrameImpl : public WebFrame {
 public:
  // Creates a new WebFrame. |initial_message_id| will be used as the message ID
  // of the next message sent to the frame with the |CallJavaScriptFunction|
  // API.
  WebFrameImpl(const std::string& frame_id,
               std::unique_ptr<crypto::SymmetricKey> frame_key,
               int initial_message_id,
               bool is_main_frame,
               GURL security_origin,
               web::WebState* web_state);
  ~WebFrameImpl() override;

  // The associated web state.
  WebState* GetWebState();

  // WebFrame implementation
  std::string GetFrameId() const override;
  bool IsMainFrame() const override;
  GURL GetSecurityOrigin() const override;

  bool CallJavaScriptFunction(
      const std::string& name,
      const std::vector<base::Value>& parameters) override;

 private:
  // The frame identifier which uniquely identifies this frame across the
  // application's lifetime.
  std::string frame_id_;
  // The symmetric encryption key used to encrypt messages addressed to the
  // frame. Stored in a base64 encoded string.
  std::unique_ptr<crypto::SymmetricKey> frame_key_;
  // The message ID of the next JavaScript message to be sent.
  int next_message_id_ = 0;
  // Whether or not the receiver represents the main frame.
  bool is_main_frame_ = false;
  // The security origin associated with this frame.
  GURL security_origin_;
  // The associated web state.
  web::WebState* web_state_ = nullptr;

  DISALLOW_COPY_AND_ASSIGN(WebFrameImpl);
};

}  // namespace web

#endif  // IOS_WEB_WEB_STATE_WEB_FRAME_IMPL_H_
